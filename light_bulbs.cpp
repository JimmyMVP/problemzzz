// There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. 
// On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
// For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

// Example:

// Given n = 3. 

// At first, the three bulbs are [off, off, off].
// After first round, the three bulbs are [on, on, on].
// After second round, the three bulbs are [on, off, on].
// After third round, the three bulbs are [on, off, off]. 

// So you should return 1, because there is only one bulb is on.


//Bad solution
class Solution {
public:
    int bulbSwitch(int n) {
        
        if(n == 0) return 0;
        int activated = 1;

        for(int i=2; i < n; i++) {
            if(!(div(i+1)%2)) activated++;
        }
        return activated;
        
    }
    
    int div(int n) {

        int x = 1;
        for(int i = n/2; i > 1; i--) {
            if(!(n%i)) x++; 
        }
        return x;
    }
};
