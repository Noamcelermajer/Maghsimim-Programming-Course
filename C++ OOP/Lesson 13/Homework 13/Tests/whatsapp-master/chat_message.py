from termcolor import colored


class ChatMessage(object):
    _AUTHOR_MAGIC = "&Author&"
    _DATA_MAGIC = "&DATA&"

    def __init__(self, message):
        author_idx = message.find(self._AUTHOR_MAGIC)
        data_idx = message.find(self._DATA_MAGIC)
        if author_idx == -1 or data_idx == -1:
            raise Exception("message %s is invalid" % message)
        author = message[author_idx + len(self._AUTHOR_MAGIC):data_idx]
        data = message[data_idx + len(self._DATA_MAGIC):]
        if not author or not data:
            raise Exception("message %s is invalid" % message)
        self.author = author
        self.data = data

    def __eq__(self, other):
        if not isinstance(other, ChatMessage):
            # don't attempt to compare against unrelated types
            return NotImplemented
        return self.author == other.author and self.data == other.data

    def pretty_print(self):
        print(' ' * 10 + colored(self.author + ": ", "blue") + colored(self.data, "green"))
