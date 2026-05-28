#include<iostream>
using namespace std;
class book{
	private:
	string book;
	string author;
	int rating[7];
	
	public:
		void data(){
			cout<<"Enter the book name:  "<<endl;
			cin>>book;
			cout<<"Enter the author name: "<<endl;
			cin>>author;
			for(int i=0;i<7;i++){
			
			cout<<"Enter the ratings for book "<<endl;
			cin>>rating[i];
			}
		}
		int average_rating(){
			int total=0;
			int average;
			for(int i=0; i<7; i++){
				total+=rating[i];
			
			}
				average = total/7;
				return average;
		}
		
		int highest_rating(){
			int max=rating[0];
			
			for(int i=0; i<7; i++){
				if(rating[i]>max){
					max=rating[i];
					
					
				}
			}
			return max;
		}
		void display(){
			cout<<"Book name: "<<book<<endl;
			cout<<"Author name: "<<author<<endl;
			for(int i=0; i<7; i++){
			
				cout<<"Rating "<<i+1<<": "<<rating[i]<<endl;
			}
			cout<<"Highest rating: "<<highest_rating()<<endl;
			cout<<"Average of rating is: "<<average_rating()<<endl;
			
		}		
	
};
int main(){
	book b;
	b.data();
	b.display();
	return 0;
}