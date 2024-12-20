#include <string>
#include <vector>

std::string longest(const std::vector<std::string>& strings) {
    std::string out;
    for (const auto& s : strings) {
        if (s.size() > out.size()) {
            out = s;
        }
    }
    return out;
}

int main() {
    std::vector<std::string> strings;

    // Test case 1: Empty array
    strings.clear();
    auto result = longest(strings);
    if (result != "") {
        std::cout << "Test case 1 failed: assertion failed" << std::endl;
        return 1;
    }

    // Test case 2: Array with single character strings
    strings = {"x", "y", "z"};
    result = longest(strings);
    if (result != "x") {
        std::cout << "Test case 2 failed: assertion failed" << std::endl;
        return 1;
    }

    // Test case 3: Array with varying length strings
    strings = {"x       ", "yyy     ", "zzzz    ", "www     ", "kkkk    ", "abc     "};
    result = longest(strings);
    if (result != "zzzz    ") {
        std::cout << "Test case 3 failed: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

### 3.2.2. æ½è±¡æ°æ®ç±»å

æ½è±¡æ°æ®ç±»åï¼ADTï¼æ¯ä¸ç§æ°æ®ç±»åï¼å®ææ°æ®åæä½æ°æ®çæ¹æ³ç»åå¨ä¸èµ·ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªéè¦ä¼ç¹æ¯ï¼å®å¯ä»¥éèæ°æ®çå®ç°ç»èã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸ä¸ªç¼ºç¹æ¯ï¼å®ä»¬éå¸¸æ¯æ®éçæ°æ®ç±»åæ´æ¢ã

æ½è±¡æ°æ®ç±»åçä¸
