from termcolor import colored

from chat_message import ChatMessage


class Chat(object):
    _CHAT_MSG_MAGIC = "&MAGSH_MESSAGE&"

    def __init__(self, current_user_name, participant_user_name):
        self.current_user_name = current_user_name
        self.participant_user_name = participant_user_name
        self.chat_messages = []

    def update_chat_data(self, full_chat_str):
        messages = [msg for msg in full_chat_str.split(self._CHAT_MSG_MAGIC) if msg]
        self.chat_messages = []
        for msg in messages:
            self.chat_messages.append(ChatMessage(msg))

    def pretty_print(self):
        print(colored(' '*5 + "Chat content for " + self.current_user_name + " <=> " +
                      self.participant_user_name, "red"))
        if len(self.chat_messages) == 0:
            print(' '*10 + "<Chat is empty>")
        for msg in self.chat_messages:
            msg.pretty_print()
