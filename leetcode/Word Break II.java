/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

----------------------------------------------------------------------

Edge case: If word dict doesn't contain any word in string s

Hashmap + recursion. Key part to save time is to avoid solving the same subproblem over and over again. Can make use of DFS + memoization + branch pruning to achieve that. 

Time: O(2^N) = O(N^2 + 2^N + W) where N = length of string, W = no. of words in dictionary
Space:
*/

public List<String> wordBreak(String wordToBreak, List<String> wordDict) {        
    return findSolutions(wordToBreak, wordDict, new HashMap<>());
}

public List<String> findSolutions(String wordToBreak, List<String> wordDict, Map<String, List<String>> wordBrokenDict) {

	// wordToBreak = catsanddog, sanddog, dog
	// 				 catsanddog, anddog

    if (wordBrokenDict.containsKey(wordToBreak)) {
        return wordBrokenDict.get(wordToBreak);
    }
    
    List<String> solutions = new ArrayList<>();
    for (String word : wordDict){
        if (!wordToBreak.startsWith(word)) {
            continue;
        }
        
        if(wordToBreak.length() == word.length()){
            solutions.add(word);
            continue;
        }
        
        List<String> subSolutions = findSolutions(wordToBreak.substring(word.length()), wordDict, wordBrokenDict);
        
        for (String subSolution: subSolutions) {
            StringBuilder sb = new StringBuilder();
            sb.append(word).append(' ').append(subSolution);
            solutions.add(sb.toString());
        }
    }
    
    wordBrokenDict.put(wordToBreak, solutions);
    return solutions;
}



















