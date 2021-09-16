/*
Problem Statement:
N meetings in one room 
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/
  
    // A utility function that is used for sorting
    // activities according to finish time
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        //declaring vector of pairs
        vector<pair<int, int>>meetings;
        for(int i=0; i<n; i++){
            meetings.push_back(make_pair(start[i], end[i]));
        }
      
      //By default the sort function sorts the vector elements on basis of first element of pairs.
      //To sort the elements of vector on the basis of second elements of pair, we modify the sort() function 
      //and we pass a third argument, a call to an user defined explicit function in the sort() function.
        sort(meetings.begin(), meetings.end(), sortbysec);
        
        int last = meetings[0].second;
        int maximum = 1;
        for(int i=1; i<n; i++){
          // If this activity has start time greater than or
          // equal to the finish time of previously selected
          // activity, then increment maxmimum variable
            if(meetings[i].first>last){
                maximum++;
                last=meetings[i].second;;
            }
        }
        return maximum;
    }
