class ServerMessage(object):
    def __init__(self, chat_data, participant_name, all_users_str):
        self.participant_name = participant_name
        self.chat_data = chat_data
        self.users = [user for user in all_users_str.split("&") if user]
