unordered_map<string, string> hashmap;
string base = "http://tinyurl.com/";
int counter = 0;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = to_string(counter);
        hashmap[key] = longUrl;
        counter++;
        return base + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(base.size());
        return hashmap[key];
    }
};