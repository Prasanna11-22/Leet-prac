class Solution {
public:
int gc(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;

    if(a>b) return gc(a%b,b);
    else return gc(a,b%a);
}
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y) return false;
        int g=gc(x,y);
        return (target%g==0);
    }
};