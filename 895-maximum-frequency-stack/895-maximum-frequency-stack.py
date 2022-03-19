class FreqStack:
    def __init__(self):
        self.freq = {}
        self.m = {}
        self.max_freq = 0
        

    def push(self, val: int) -> None:
        if val not in self.freq:
            self.freq[val] = 1
        else:
            self.freq[val] += 1
        
        self.max_freq = max(self.max_freq, self.freq[val])
        
        if self.freq[val] not in self.m:
            self.m[self.freq[val]] = [val]
        else:
            self.m[self.freq[val]].append(val)
            

    def pop(self) -> int:
        ret = self.m[self.max_freq].pop()
        self.freq[ret] -= 1
        
        if len(self.m[self.max_freq]) == 0:
            self.max_freq -= 1
        
        return ret


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()