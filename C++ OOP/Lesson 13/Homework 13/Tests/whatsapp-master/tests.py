import random
import string

from Client import Client
from participant import Participant


def create_user_and_login(user_name):
    c = Client(user_name)
    c.connect()
    c.login()
    c.update_client()
    return c


def validate_users(client, expected_users):
    assert isinstance(client, Client)
    assert [p.participant_name for p in client.participants].sort() == expected_users.sort(), "Failed to get all " \
                                                                                              "users from server"


def get_participant_by_name(client, par_name):
    assert isinstance(client, Client)
    filtered_list = [p for p in client.participants if p.participant_name == par_name]
    assert len(filtered_list) == 1
    return filtered_list[0]


def print_clients(*argv):
    for arg in argv:
        assert isinstance(arg, Client)
        arg.pretty_print()


def update_clients(*argv):
    for arg in argv:
        assert isinstance(arg, Client)
        arg.update_client()


def get_random_user_name(prefix):
    return prefix + "_" + ''.join(random.choice(string.ascii_lowercase) for x in range(5))


def multiple_users_test():
    users = [get_random_user_name("first_user"), get_random_user_name("second_user"),
             get_random_user_name("third_user")]
    print("Adding 3 new users")
    c1 = create_user_and_login(users[0])
    c2 = create_user_and_login(users[1])
    c3 = create_user_and_login(users[2])
    update_clients(c1, c2, c3)
    print_clients(c1, c2, c3)

    validate_users(c1, users)
    validate_users(c2, users)
    validate_users(c3, users)

    message = "Hi, how are you today?"
    print("Sending messages between users and validates")
    # First user sending message to second user
    par: Participant = get_participant_by_name(c1, users[1])
    par.send_message(message)
    update_clients(c1, c2, c3)

    par = get_participant_by_name(c1, c2.client_name)
    assert isinstance(par, Participant)
    assert len(par.chat.chat_messages) == 1 and par.chat.chat_messages[0].author == c1.client_name and \
           par.chat.chat_messages[0].data == message

    par = get_participant_by_name(c2, c1.client_name)
    assert isinstance(par, Participant)
    assert len(par.chat.chat_messages) == 1 and par.chat.chat_messages[0].author == c1.client_name and \
           par.chat.chat_messages[0].data == message

    update_clients(c1, c2, c3)
    print_clients(c1, c2, c3)


def main():
    multiple_users_test()
    print("Good job :)")


if __name__ == '__main__':
    main()
