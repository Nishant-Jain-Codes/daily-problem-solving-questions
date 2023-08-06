class work{
    public: 
    int type ; 
    int dayGiven;
    int daysLeft;
    int deadLine;
    work(int type , int dayGiven ,int daysLeft,int deadLine){
        this->type=type;
        this->dayGiven = dayGiven;
        this->daysLeft=daysLeft;
        this->deadLine = deadLine;
    }
};

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> answer(A+1,0);
    answer[0]=-1;
    vector<work>works(B.size());
    for(int i=0;i<B.size();i++){
        works[i] = work(i+1,B[i][0],B[i][2],B[i][1]);
    }
    sort(works.begin(),works.end(),[](work & a , work& b){
        return a.dayGiven<b.dayGiven;
    });
    struct Comp{
        bool operator()(const work& w1 , const work &w2){
            return w1.deadLine < w2.deadLine;
        }
    };
    int worksIdx = 0;
    priority_queue<work,vector<work>, Comp>pq;
    int day = 1;
    while(day<=A){
        if(day == works[worksIdx].dayGiven){
            pq.push(works[worksIdx]);
            worksIdx++;
        }
        if(pq.empty()){
            answer[day]=0;
            day++;
        }
        else{
            work curWork = pq.top();
            pq.pop();
            int dayGiven = curWork.dayGiven;
            int workType = curWork.type;
            int daysLeft = curWork.daysLeft;
            int deadLine = curWork.deadLine;
            
            if(deadLine == day && daysLeft >0){
                break;
            }
            else if(answer[day]!=0){
                day++;
            }
            else{
                answer[day]=workType;
                daysLeft--;
                if(daysLeft  > 0 ){
                    curWork.daysLeft = daysLeft;
                    pq.push(curWork);
                }
                else {
                    answer[deadLine]=deadLine;
                }
                day++;
            }
        }
    }
    if(!pq.empty()||worksIdx<works.size())
        {
            vector<int> noAns = {-1};
            return noAns;
        }
    return answer;
}