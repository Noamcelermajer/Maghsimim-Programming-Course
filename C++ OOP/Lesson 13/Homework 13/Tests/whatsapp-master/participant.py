from termcolor import colored

from chat import Chat
from server_comm import ServerComm
from server_message import ServerMessage


class Participant(object):
    def __init__(self, user_name, par_name, server_comm):
        assert len(user_name) > 0 and len(par_name) > 0
        assert isinstance(server_comm, ServerComm)
        self.user_name = user_name
        self.participant_name = par_name
        self.server_comm = server_comm
        self.logged_in = True
        self.chat = Chat(self.user_name, self.participant_name)

    def __eq__(self, other):
        if not isinstance(other, Participant):
            # don't attempt to compare against unrelated types
            return NotImplemented
        return self.participant_name == other.participant_name

    def update_chat(self):
        self.server_comm.send_server_update_msg(self.participant_name)
        server_message = self.server_comm.rvc_server_update()
        assert isinstance(server_message, ServerMessage)
        assert self.participant_name == server_message.participant_name, "Participant name in server update message " \
                                                                         "is not equal to the requested username"
        self.chat.update_chat_data(server_message.chat_data)

    def send_message(self, msg):
        assert msg and isinstance(msg, str), "Message should be non empty str"
        self.server_comm.send_server_update_msg(self.participant_name, msg)
        self.server_comm.rvc_server_update()

    def pretty_print(self):
        print(colored(self.participant_name, "blue") + colored(": Logged In:", "green"),
              colored(str(self.logged_in), "cyan" if self.logged_in else "red"))
        self.chat.pretty_print()
