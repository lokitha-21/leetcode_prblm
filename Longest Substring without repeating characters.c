int lengthOfLongestSubstring(char* s) {
    int char_map[256];
    memset(char_map, -1, sizeof(char_map));
    int max_length = 0;
    int start = 0;
    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char current_char = s[end];
        if (char_map[current_char] >= start) {
            start = char_map[current_char] + 1;
        }
        char_map[current_char] = end;
        int current_len = end - start + 1;
        if (current_len > max_length) {
            max_length = current_len;
        }
    }
    return max_length;
}
