class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = []
        w_num = len(words)      # how many words?
        w_cnt = Counter(words)  # word counter
        # print(f'w_cnt: {w_cnt}')
        
        
        w_len = len(words[0])   # all words have same length
        
        for start in range(w_len):
            s_list = []             # split s into words with length w_len

            i = start
            while i < len(s):
                s_list.append(s[i:i+w_len])
                i += w_len

            window = Counter(s_list[:w_num-1])
            for i in range(len(s_list) - w_num + 1):
                # add s_list[i+w_num-1] to window
                window[s_list[i+w_num-1]] += 1

                # print(f'window: {window}')
                if window == w_cnt:
                    # print(f'index: {i*w_len + start}')
                    ans.append(i*w_len + start)

                # delete s_list[i] from window
                if window[s_list[i]] <= 1:
                    del window[s_list[i]]
                else:
                    window[s_list[i]] -= 1

            # print('----------------------')
        return ans