//Math solution: perfect squares have an odd number of factors
public class Solution {
    public int bulbSwitch(int n) {
        
        int active = 0;
        for(int i = 1; i <= Math.sqrt(n); i++) {
            active++;
        }
        return active;
        
    }
}