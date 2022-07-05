class Solution {
private:
    string mapper = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMONPQRSTUVWXYZ012345679";
    unordered_map<string, string> longurl_to_short, shorturl_to_long;
    random_device rd;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = "";
        
        if(longurl_to_short.find(longUrl) == longurl_to_short.end())
        {
            for(int i = 0; i < 6; i++)// find a 6 digit random number
            {
                char rand_character = mapper[rd() % mapper.size()];
                code.push_back(rand_character);
            }
            
                longurl_to_short[longUrl] = code;
                shorturl_to_long[code] = longUrl;
        }
        else
            code = longurl_to_short[longUrl];
        
        
        return "http://tinyurl.com/" + code;
            
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(19, 6);
        
        if(shortUrl.size() != 25 | shorturl_to_long.find(code) == shorturl_to_long.end())
            return "";
        
        return shorturl_to_long[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));