class Solution {
private:
    string seeds = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> url2tiny;
    unordered_map<string, string> tiny2url;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(!url2tiny.count(longUrl)){
            random_shuffle(seeds.begin(), seeds.end());
            string tiny = seeds.substr(0, 6);
            if(!tiny2url.count(tiny)){
                tiny2url[tiny] = longUrl;
                url2tiny[longUrl] = tiny;
            }

        }
        return "http://tinyurl.com/"+url2tiny[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int p = shortUrl.find_last_of("/");
        return tiny2url[shortUrl.substr(p+1)];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
