class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        files = {}
        for path in paths:
            info = path.split(" ")
            # print(info)
            directory = info[0]
            for i in range(1, len(info)):
                file_info = info[i].split("(")
                file_name = file_info[0]
                file_content = file_info[1].replace(")", "")
                # file_content = file_info[1][:-1]
                # print(file_name, file_content)
                if file_content not in files:
                    files[file_content] = []
                files[file_content].append(directory+"/"+file_name)
            
        # print(files)
        return list(filter(lambda f: len(f) >= 2, files.values()))