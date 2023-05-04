from termcolor import colored

from participant import Participant
from server_comm import ServerComm
from server_message import ServerMessage
from consts import ServerIP, ServerPort


class Client(object):
    def __init__(self, client_name):
        self.client_name = client_name
        assert 0 < len(client_name) < 99, "Client name length should be longer then 0 and shorter then 99"
        self.server_comm = ServerComm(ServerIP, ServerPort)
        self.participants = []

    def connect(self):
        self.server_comm.connect()

    def login(self):
        login_data = "200" + str(len(self.client_name)).rjust(2, '0') + str(self.client_name)
        self._send_data(login_data)
        server_message = self._rcv_msg()
        self._handle_server_update(server_message)

    def update_client(self):
        self.server_comm.send_server_update_msg()
        server_message = self._rcv_msg()
        self._handle_server_update(server_message)
        for par in self.participants:
            par.update_chat()

    def _handle_server_update(self, server_message):
        assert isinstance(server_message, ServerMessage)
        assert self.client_name in server_message.users, "Current user name isn't in all users list"
        self._set_participants([p for p in server_message.users if p != self.client_name])

    def pretty_print(self):
        print(colored("User Name: " + self.client_name, "magenta"))
        print(colored("=" * 10, "magenta"))
        for p in self.participants:
            p.pretty_print()
        print()

    def _set_participants(self, user_names):
        # Set logged out users
        for p in [par for par in self.participants if par.participant_name not in user_names]:
            p.logged_in = False

        # Set logged in users
        for p in [par for par in self.participants if not par.logged_in and par.participant_name in user_names]:
            p.logged_in = True

        # Set new logged in users
        cur_user_names = [p.participant_name for p in self.participants]
        for name in [un for un in user_names if un not in cur_user_names]:
            self.participants.append(Participant(self.client_name, name, self.server_comm))

    def _rcv_msg(self):
        return self.server_comm.rvc_server_update()

    def _rcv_data(self, size):
        return self.server_comm.rcv_data(size)

    def _send_data(self, data):
        self.server_comm.send_data(data)

    def disconnect(self):
        self.server_comm.close()
