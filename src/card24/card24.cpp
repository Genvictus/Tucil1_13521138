#include "card24.h"
// #include <vector>
// #include <string>
// #include <set>

// using namespace std;

vector<string> solve24(vector<int> nums){
    /* KAMUS LOKAL */
    vector<string> solutions;
    vector<expression> expressions;
    vector<vector<int>> permutations;

    vector<vector<int>>::iterator it;
    vector<expression>::iterator jt;

    /* ALGORITMA */
    permutations = permute(nums);
    for(it = permutations.begin(); it != permutations.end(); ++it){
        expressions = count24(*it);
        for(jt = expressions.begin(); jt != expressions.end(); ++jt){
            if(jt->val == 24){
                solutions.push_back(jt->expr);
            }
        }
    }
    return solutions;
}

vector<vector<int>> permute(vector<int> nums){
    /* KAMUS LOKAL */
    vector<int> subnums;
    vector<int>::iterator n_it, subn_it;

    set<vector<int>> solutions;
    set<vector<int>>::iterator s_it;

    vector<vector<int>> nextpermute;
    vector<vector<int>>::iterator p_it;

    vector<vector<int>> solutionvec;

    /* ALGORITMA */
    /* BASIS */
    if(nums.size() == 1){
        solutionvec.push_back(vector<int>(nums));
        return solutionvec;
    }
    /* REKURENS */
    else{
        for(n_it = nums.begin(); n_it != nums.end(); ++n_it){
            /* create subset of number to permute */
            subnums.clear();
            subnums.insert(subnums.begin(), nums.begin(), n_it);
            subnums.insert(subnums.end(), n_it+1, nums.end());

            /* find next permutations based on remaining elements */
            nextpermute = permute(subnums);

            /* insert (append) current element not in subset of permuted remaining elements */
            for(p_it = nextpermute.begin(); p_it != nextpermute.end(); ++p_it){
                (*p_it).push_back(*n_it);
                solutions.insert(*p_it);
            }
        }
        solutionvec.assign(solutions.begin(), solutions.end());
        return solutionvec;
    }
}

vector<expression> count24(vector<int> nums){
    /* KAMUS LOKAL */
    vector<int> subnums;
    vector<int>::iterator it;

    vector<expression> left, right;
    vector<expression>::iterator l_it, r_it;

    expression temp;

    vector<expression> solutions;

    /* ALGORITMA */
    /* BASIS */
    if(nums.size() == 1){
        temp.expr = to_string(*(nums.begin()));
        temp.val = *(nums.begin());
        solutions.push_back(temp);
        return solutions;
    }
    /* REKURENS */
    else{
        for(it = nums.begin(); it != nums.end()-1; ++it){
            /* segment */
            subnums.clear();
            subnums.insert(subnums.begin(), nums.begin(), it+1);
            left = count24(subnums);
            subnums.clear();
            subnums.insert(subnums.begin(), it+1, nums.end());
            right = count24(subnums);

            for(l_it = left.begin(); l_it != left.end(); ++l_it){
                for(r_it = right.begin(); r_it != right.end(); ++r_it){
                    /* + */
                    temp.expr = "(" + l_it->expr + " + " + r_it->expr + ")";
                    temp.val = l_it->val + r_it->val;
                    solutions.push_back(temp);
                    /* - */
                    temp.expr = "(" + l_it->expr + " - " + r_it->expr + ")";
                    temp.val = l_it->val - r_it->val;
                    solutions.push_back(temp);
                    /* * */
                    temp.expr = "(" + l_it->expr + " * " + r_it->expr + ")";
                    temp.val = l_it->val * r_it->val;
                    solutions.push_back(temp);
                    /* / */
                    if(r_it->val != 0){
                        temp.expr = "(" + l_it->expr + " / " + r_it->expr + ")";
                        temp.val = l_it->val / r_it->val;
                        solutions.push_back(temp);
                    }
                }
            }
        }
        return solutions;
    }
}