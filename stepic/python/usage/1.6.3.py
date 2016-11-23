class LoggableList(list, Loggable):
    def append(element):
        super(LoggableList, self).append(element)
        self.log(element)
