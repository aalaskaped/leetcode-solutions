char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    char *first = strs[0];
    int i = 0;

    while (first[i] != '\0') {
        char c = first[i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != c) {
                char *res = (char*)malloc(i + 1);
                strncpy(res, first, i);
                res[i] = '\0';
                return res;
            }
        }
        i++;
    }

  
    char *res = (char*)malloc(i + 1);
    strcpy(res, first);
    return res;
}

