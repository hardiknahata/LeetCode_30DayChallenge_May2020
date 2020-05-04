/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its 
binary representation.

Input: 5
Output: 2

Explanation:
The binary representation of 5 is 101 (no leading zero bits), 
and its complement is 010. So you need to output 2.
*/

class Solution {
public:
    unsigned int findComplement(unsigned int n) 
    {
        unsigned int mask = 2147483648; //mask is the highest possible binary number
        string bin="";
        
        // Converting to Binary
        while(mask>0)
        {
            if( (n & mask) == 0)
                bin+="0";
            else
                bin+="1";
            
            mask = mask >> 1;
        }
        
        //Removing extra zeros from binary representation
        bin=bin.substr(bin.find("1"));
            
        // Complementing bits in Binary representation
        for(int i=0;i<bin.size();i++)
        {
            if(bin[i]=='1')
                bin[i]='0';
            else
                bin[i]='1';
        }

        // Converting Complemented Binary to Decimal
        unsigned int dec_val = 0, base=0;
        
        for(int i=bin.size()-1;i>=0;i--)
        {
            if(bin[i]=='1')
                dec_val += pow(2,base);
            base++;
        }
                       
    return dec_val;
    }
};

// Algorithm/Data Structure: Bit Manipulation  
// TC: O(n)
// SC: O(1)
