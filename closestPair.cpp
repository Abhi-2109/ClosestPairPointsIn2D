#include<bits/stdc++.h>
using namespace std;
float distance(pair<float,float> p1,pair<float,float> p2)
{
    return sqrt((p1.first-p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}
bool compare1(pair<float,float> p1,pair<float,float> p2)
{
    return p1.first < p2.first;
}
bool compare2(pair<float,float> p1,pair<float,float> p2)
{
    return p1.second < p2.second;
}
pair<pair<float,float>,pair <float,float>> closestPair(vector <pair<float,float>> points)
{
    int no = points.size();
    if(no > 3)
    {
        vector <pair<float,float>> pointsX(points);
        sort(pointsX.begin(),pointsX.end(),compare1);
        int mid = pointsX.size()/2;
        vector <pair<float,float>> part1,part2;
        for(int i = 0; i < mid; i++)
            part1.push_back(pointsX[i]);
        for(int i = mid; i < pointsX.size(); i++)
            part2.push_back(pointsX[i]);
        pair<pair<float,float>,pair <float,float>> part1Ans(closestPair(part1));
        pair<pair <float,float>,pair <float,float>> part2Ans(closestPair(part2));
        pair < pair<float,float>, pair<float,float>> MainAns;
        float part1Distance = distance(part1Ans.first,part1Ans.second);
        float part2Distance = distance(part2Ans.first,part1Ans.second);
        float dis;
        if(part1Distance > part2Distance)
        {
            MainAns = part2Ans;
            dis = part2Distance;
        }
        else
        {
            MainAns = part1Ans;
            dis = part1Distance;
        }
        for(int i = 0;i < part1.size(); i++)
        {
            if(part1[i].first < dis)
            {
                for(int j = 0; j < part2.size(); j++)
                {
                    if(part2[j].first < dis)
                    {
                        if(distance(part1[i],part2[j]) < dis)
                        {
                            MainAns = make_pair(part1[i],part2[j]);
                            dis = distance(part1[i],part2[j]);
                        }
                    }
                }
            }
        }
       return MainAns;
    }
    else if(no ==2)
        return make_pair(points[0],points[1]);
    else
    {
        float dis1 = distance(points[0],points[1]);
        float dis2 = distance(points[1],points[2]);
        float dis3 = distance(points[0],points[2]);
        if(dis1 <= dis2 && dis1 <= dis3)
            return make_pair(points[0],points[1]);
        else if(dis2 <= dis1 && dis2 <= dis3)
            return make_pair(points[1],points[2]);
        else
            return make_pair(points[0],points[2]);
    }
}
int main()
{
    int n;
    cout << "Enter no of points : ";
    cin >> n;
    vector < pair <float,float> > points;
    for(int i = 0; i < n ; i++)
    {
        float tempX,tempY;
        cout << "Enter Point " << i << ":" << endl;
        cout << "\tX :";
        cin >> tempX;
        cout << "\tY :";
        cin >> tempY;
        points.push_back(make_pair(tempX,tempY));
    }
    float minDistance = distance(points[0],points[1]);
    for(int i = 0; i < points.size(); i++)
    {
        for(int j = i+1; j < points.size(); j++)
        {
            if(minDistance > distance(points[i],points[j]))
            {
                minDistance = distance(points[i],points[j]);
            }
        }
    }
    cout << minDistance << endl;
    pair<pair<float,float>,pair<float,float>> Ans = closestPair(points);

    cout << "The closest Point in the 2D sapce is :"<< endl;
    cout << Ans.first.first << "  " << Ans.first.second  << endl;
    cout << Ans.second.first << "  " << Ans.second.second  << endl;
    cout << "The Distance Between Them is "<< distance(Ans.first,Ans.second);

    return 0;
}
