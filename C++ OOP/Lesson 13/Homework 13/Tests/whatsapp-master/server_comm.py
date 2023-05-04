import socket

from server_message import ServerMessage


class ServerComm(object):
    def __init__(self, server_ip, server_port):
        self.server_ip = server_ip
        self.server_port = server_port
        self.server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        self.server_sock.connect((self.server_ip, self.server_port))

    def send_data(self, data):
        if not data:
            return
        self.server_sock.sendall(data.encode())

    def send_server_update_msg(self, participant_user=None, msg_to_send=None):
        u = participant_user if participant_user else ""
        m = msg_to_send if msg_to_send else ""
        update_data = "204" + str(len(u)).rjust(2, '0') + str(u) + \
                      str(len(m)).rjust(5, '0') + str(m)
        self.send_data(update_data)

    def rvc_server_update(self):
        # Get server message code
        code = int(self.rcv_data(3))
        assert code == 101, "Server update code message should be 101"

        # Get chat data
        chat_size = int(self.rcv_data(5))
        chat_data = self.rcv_data(chat_size)

        # Get participant name
        participant_username_len = int(self.rcv_data(2))
        participant_username = self.rcv_data(participant_username_len)

        # Get all available user names
        user_names_len = int(self.rcv_data(5))
        user_names = self.rcv_data(user_names_len)
        # print("code: " + str(code), "chat_size: " + str(chat_size),
        #       "participant_username_len: " + str(participant_username_len), "user_names_len: " + str(user_names_len))
        return ServerMessage(chat_data=chat_data, participant_name=participant_username, all_users_str=user_names)

    def rcv_data(self, size):
        if size == 0:
            return ""
        return self.server_sock.recv(size).decode()

    def close(self):
        self.server_sock.close()
