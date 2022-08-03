class MyCalendar:

    def __init__(self):
        self.schedule = []

    def book(self, start: int, end: int) -> bool:
        can_book = True
        for s_pre, e_pre in self.schedule:
            can_book = e_pre <= start or end <= s_pre
            if can_book == False:
                break
        
        if can_book:
            self.schedule.append((start, end))
        
        return can_book
            


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)