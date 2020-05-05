/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its 
binary representation.

Input: 5
Output: 2

Explanation:
The binary representation of 5 is 101 (no leading zero bits), 
and its complement is 010. So you need to output 2.
*/

// SOLUTION 1 O(n)
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


// SOLUTION 2 O(1)
class Solution {
public:
    int findComplement(int n) 
    {
        int t=n;
        int x=1;
        
        while(t!=0)
        {
            x = x<<1;
            t = t>>1;
        }
        
    return n^(x-1);
    }
};

// Algorithm/Data Structure: Bit Manipulation  
// TC: O(1)
// SC: O(1)
