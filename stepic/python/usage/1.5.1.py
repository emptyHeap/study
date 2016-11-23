class MoneyBox:
    def __init__(self, capacity):
        self.capacity = capacity
        self.amount = 0

    def remain(self):
        return self.capacity - self.amount

    def can_add(self, v):
        if self.remain() >= v:
            return true
        else :
            return false

    def add(self, v):
        self.amount += v

