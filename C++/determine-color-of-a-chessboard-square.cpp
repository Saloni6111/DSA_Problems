class Solution {
public:
    bool squareIsWhite(string coordinates) {
        switch(coordinates[0]){
            case 'a':
                if ((int(coordinates[1])-48)%2==0){
                    return true;
                }else{return false;}
            case 'b':
                if ((int(coordinates[1])-48)%2==0){
                    return false;
                }else{return true;}
            case 'c':
                if ((int(coordinates[1])-48)%2==0){
                    return true;
                }else{return false;}
            case 'd':
                if ((int(coordinates[1])-48)%2==0){
                    return false;
                }else{return true;}
            case 'e':
                if ((int(coordinates[1])-48)%2==0){
                    return true;
                }else{return false;}
            case 'f':
                if ((int(coordinates[1])-48)%2==0){
                    return false;
                }else{return true;}
            case 'g':
                if ((int(coordinates[1])-48)%2==0){
                    return true;
                }else{return false;}
            
            case 'h':
                if ((int(coordinates[1])-48)%2==0){
                    return false;
                }else{return true;}

          
        }
        return false; 
    }
};