class Solution {
public:
    int calPoints(vector<string>& operations) {

        int n = operations.size();

        vector<int> record;
        // storing the scores of the baseball means!!

        for(int i = 0; i < n; i++){

            if(operations[i] != "D" && operations[i] != "C" && operations[i] != "+"){

                record.push_back(stoi(operations[i]));
                // We need to push the scores in the form of integers, and stoi function helps us convert string to an integer
            }
            else if(operations[i] == "+"){

                record.push_back(record[record.size()-1] + record[record.size()-2]);
                // size of the record array could be smaller than the index, so each time we want to access elements from last of the array
                // we will use record.size() for that purpose!!
            }
            else if(operations[i] == "C"){

                record.pop_back();
                
            }
            else if(operations[i] == "D"){

                record.push_back(2 * record[record.size()-1]);
            }
        }

        int sum = 0;
        // sum variable will be storing the sum of all records

        for(int i = 0; i < record.size(); i++){

            sum += record[i];

        }
        
        return sum;
        
    }
};