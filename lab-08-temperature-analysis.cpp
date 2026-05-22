#include<iostream>
using namespace std;
class temperature{
	private:
	double temp[7];
	public:
	void data(){
		for(int i=0; i<7; i++){
			
		cout<<"Enter temperatures: "<<endl;
		cin>>temp[i];
    	}
	}
	double Highest_temp(){
		double max=temp[0];
		for(int i=0; i<7; i++){
			if(temp[i]>max){
				max=temp[i];
			}
		}
		return max;
	}
	
		double Lowest_temp(){
		double min=temp[0];
		for(int i=0; i<7; i++){
			if(temp[i]<min){
				min=temp[i];
			}
		}
		return min;
	}
	double average(){
		double total=0;
		double avg;
		for(int i=0; i<7; i++){
			
			total+=temp[i];	
		}
		avg = total/7;
		return avg;
		
	}
	void display(){
		for(int i=0; i<7; i++){
			cout<<"Temperature"<<i+1<<": "<<temp[i]<<endl;	
		}
		cout<<"Highest temperature : "<<Highest_temp()<<endl;
		cout<<"Lowest temperature : "<<Lowest_temp()<<endl;
		cout<<"Average temperature : "<<average()<<endl;
		
	}
};
int main(){
	temperature t;
	t.data();
	t.display();
	return 0;
}