import os


class ConsoleUtilities:

    @staticmethod
    def clear_console():
        os.system('cls' if os.name == 'nt' else 'clear')
