/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

-----------------------------------------------------------------------

Edge case: If length of accounts array = 1, just return it. 

Union find approach. 
- Assign each email to unique id from 0 to N 
- Resultant map will map id to the group of corresponding emails
- Then replace the id with account name  

Time: O(N log N) where N = num of emails
Space: O(N) = O(NK) where K = max length of account
*/

int parents[1001]; // 1 <= accounts.length <= 1000
    
int findParent(int to_find) {
	while(parents[to_find] != to_find) {
	    to_find = parents[to_find];
	}
	return to_find; 
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	if (accounts.size() == 1) {
        sort(accounts[0].begin()+1, accounts[0].end());
        return accounts;
    }

    unordered_map<string, int> email_to_id;

	for (int i = 0; i < accounts.size(); i++) {
        parents[i] = i; // initialise, every parent is unique id of itself
        for (int j = 1; j < accounts[i].size(); j++) { // start from cos emails start from this place
        	// check if this particular email already got their unique id, if yes then link it to its original parent unique id
            if (email_to_id.find(accounts[i][j]) != email_to_id.end()) {
                int parent1 = findParent(i);
                int parent2 = findParent(email_to_id[accounts[i][j]]);
                parents[parent1] = parent2;
            } else { // give to existing parent
            	email_to_id[accounts[i][j]] = parents[i];
            }
        }
    }

    // email_to_id map = {john@gmail.com, 0}, {john@yahoo.com, 0}, {mary@gmail.com, 1}

    // Create map that stores all email id with their unique ids
    unordered_map<int, vector<string>> resultant_map;
    // resultant_map = {0, <john@gmail.com, john@yahoo.com>}, {1, <mary@gmail.com>}
    
    for (auto i : email_to_id) {
        int uniq_id = findParent(i.second); 
        resultant_map[uniq_id].push_back(i.first);
    }
    
    vector<vector<string>> ans;
    for (auto i : resultant_map) {
        vector<string> email = i.second;
        sort(email.begin(), email.end()); // question wants sorted order
        
        // insert name using unique id
        email.insert(email.begin(), accounts[i.first][0]);
        ans.push_back(email);
    }
	return ans;
	// ans = {John, <john@gmail.com, john@yahoo.com>}, {Mary, <mary@gmail.com>}
}















