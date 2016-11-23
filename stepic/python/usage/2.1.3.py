class NonPositiveError(Exception):
    pass

class PositiveList(list):
    def append(number):
        if not (number > 0):
            raise NonPositiveError()
        else:
            list.append(self, number) 
