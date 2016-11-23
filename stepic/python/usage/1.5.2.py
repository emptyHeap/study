class Buffer:
    def __init__(self):
        self.sequence = []
    
    def trunc_sequence(self):
        if (len(self.sequence) > 4):
            subsequences = len(self.sequence) / 5
            for i in range(subsequences):
                print(sum(self.sequence[(i * 5):( (i+1) * 5)]))
            self.sequence = self.sequence[subsequences * 5:]

    def add(self, *elements):
        self.sequence.extend(elements)
        self.trunc_sequence()

    def get_current_part(self):
        return self.sequence
