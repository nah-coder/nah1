#include <iostream>
#include <iomanip> 
#include <fstream> 
#include <string.h>
#include <cstring>
using  namespace  std ; 
struct  kiemtra
{ 
	char  SBD [20]; 
	char  tenHs [30]; 
	float toan,ly,hoa;
	float tongdiem ; 
	char ketqua[10] ;
}; 
void menu(){
	cout<<"\n\t\t*************************************-MENU-*****************************************";
	cout<<"\n\t\t** 1 .Nhap danh sach hoc sinh.					                  **";
	cout<<"\n\t\t** 2 .Tinh tong diem hoc sinh.					                  **";
	cout<<"\n\t\t** 3 .In danh sach thong tin hoc sinh.		                                  **";	
	cout<<"\n\t\t** 4 .In thong tin hoc sinh thi dat.			                          **";	
	cout<<"\n\t\t** 5 .Sap xep cac hoc sinh giam dan theo tong diem.		                  **";
	cout<<"\n\t\t** 6 .Nhap them thong tin mot thi sinh. 	                                  **";
	cout<<"\n\t\t** 7 .Xoa thong tin thi sinh..  	                                          **";
	cout<<"\n\t\t** 8 .Luu danh sach thi sinh ra tep chatluong.dat.  	                          **";
	cout<<"\n\t\t** 9 .Doc danh sach thi sinh tu tep chatluong.dat va thong tin ra man hinh .  	  **";
	cout<<"\n\t\t** 0 .Thoat Chuong Trinh!!!!!				       	      	  	  **";
	cout<<"\n\t\t************************************************************************************";
}
void  nhap(kiemtra  hs[], int &n )  
{ 	cout<<"\nNhap so luong hoc sinh : ";
	cin>>n;
	for ( int  i= 0 ; i < n ; i ++ ) 
	{ 
	cout<<"\nNhap thong tin cho hoc sinh thu :"<<i+1<<endl ; 
	fflush(stdin); 
	cout << "\tSo bao danh : " ; 
	cin.getline(hs[i].SBD,20 ); 
	cout << "\tTen hoc sinh : ";
	cin.getline(hs[i].tenHs,30);
	cout << "\tToan : " ;
	cin>>hs[i].toan ; 
	cout << "\tLy  : " ;
	cin>>hs[i].ly ; 
	cout << "\tHoa : " ;
	cin>>hs[i].hoa ; 
	} 
}
void  tieude()
{ 	cout<<"\n\n";
	cout<<"\t\t\tDANH SACH QUAN LY KIEM TRA CHAT LUONG HK1"<<endl;
	cout<<"\t\t\t\tNam hoc 2021-2022\n"<<endl;
	cout<<setw(5)<<left<<"STT";
	cout<<setw(20)<<left<<"So bao danh"; 
	cout<<setw(30)<<left<<"Ten hoc sinh"; 
	cout<<setw(10)<<left<<"Toan";
	cout<<setw(10)<<left<<"Ly";
	cout<<setw(10)<<left<<"Hoa"; 
	cout<<setw(20)<<left<< "Tong diem"; 
	cout<<setw(10)<<left<<"Ket qua"<< endl;			
} 
void  xuat(kiemtra hs[], int n) 
{ 	tieude (); 
	for ( int  i = 0 ; i < n ; i ++ ) 
	{
	cout<<setw(5)<<left<<i+1;
	cout<<setw(20)<<left<<hs[i].SBD;
	cout<<setw(30)<<left<<hs[i].tenHs;
	cout<<setw(10)<<left<<hs[i].toan;
	cout<<setw(10)<<left<<hs[i].ly;
	cout<<setw(10)<<left<<hs[i].hoa; 
	cout<<setw(20)<<left<<hs[i].tongdiem;
	cout<<setw(10)<<left<<hs[i].ketqua;	
	cout<<endl;	
	} 
} 
void  tong(kiemtra hs[], int n ) {
	for ( int  i = 0 ; i < n ; i ++ ) {
		hs[i].tongdiem=hs[i].toan+hs[i].ly+hs[i].hoa;
		cout<<"\n---Tong diem cua hoc sinh thu "<<i+1<<" : "<<hs[i].tongdiem;
	}
}
void kq(kiemtra hs[],int n)
{
	for(int i = 0; i < n; i++){
		if(hs[i].toan>=5 && hs[i].ly>=5 && hs[i].hoa>=5)
			strcpy(hs[i].ketqua,"Dat");
		else{
			if((hs[i].toan<5 && hs[i].ly>=5 && hs[i].hoa>=5)or(hs[i].toan>=5 && hs[i].ly<5 && hs[i].hoa>=5)or(hs[i].toan>=5 && hs[i].ly>=5 && hs[i].hoa<5))
				strcpy(hs[i].ketqua,"Thi lai");
			else
				strcpy(hs[i].ketqua,"Hong");
		}
	}
}
void in_dat(kiemtra hs[], int n)
{
	char d[10]="Dat";
	int k=0;
	for(int i=0;i<n;i++){
		if(strcmp(hs[i].ketqua,d)==0)
		{
			k=i;
		}
	}
	cout<<"\t\t\tDANH SACH THI SINH THI DAT"<<endl;
	cout<<setw(20)<<left<<"So bao danh"; 
	cout<<setw(30)<<left<<"Ten hoc sinh"; 
	cout<<setw(10)<<left<<"Toan";
	cout<<setw(10)<<left<<"Ly";
	cout<<setw(10)<<left<<"Hoa"; 
	cout<<setw(20)<<left<< "Tong diem"; 
	cout<<setw(10)<<left<<"Ket qua"<< endl;	
	cout<<setw(20)<<left<<hs[k].SBD;
	cout<<setw(30)<<left<<hs[k].tenHs;
	cout<<setw(10)<<left<<hs[k].toan;
	cout<<setw(10)<<left<<hs[k].ly;
	cout<<setw(10)<<left<<hs[k].hoa; 
	cout<<setw(20)<<left<<hs[k].tongdiem;
	cout<<setw(10)<<left<<hs[k].ketqua;	
	cout<<endl;		
}
void sapxep(kiemtra hs[], int n){
	for(int i=0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(hs[i].tongdiem < hs[j].tongdiem)
		    	swap(hs[i],hs[j]);
		  	}    
	
	}
	cout<<"\t\t\t\t SAP XEP TONG DIEM GIAM DAN "<<endl;
   	cout<<setw(5)<<left<<"STT"<<setw(20)<<left<<"So bao danh"<<setw(30)<<left<<"Ten hoc sinh"<<setw(10)<<left<<"Toan"<<setw(10)<<left<<"Ly"<<setw(10)<<left<<"Hoa"<<setw(20)<<left<< "Tong diem"<<setw(10)<<left<<"Ket qua"<<endl;
   	for (int i=0 ; i<n ; i++){
	cout<<setw(5)<<left<<i+1;
	cout<<setw(20)<<left<<hs[i].SBD;
	cout<<setw(30)<<left<<hs[i].tenHs;
	cout<<setw(10)<<left<<hs[i].toan;
	cout<<setw(10)<<left<<hs[i].ly;
	cout<<setw(10)<<left<<hs[i].hoa;
	cout<<setw(20)<<left<<hs[i].tongdiem;
	cout<<setw(10)<<left<<hs[i].ketqua;	
	cout<<endl;
    }
}
void themhs(kiemtra hs[], int &n){
	kiemtra hs1;
	cout<<"\nNhap thong tin cho hoc sinh : ";
	cin.ignore();
	bool kiemtra; 
			do
			{
				kiemtra  = true ;
				cout<<"\nNhap SBD cho hs: ";
				cin.getline(hs1.SBD,20);
				for ( int i = 0 ; i< n ; i++ )
				{
					if (strcmpi(hs1.SBD,hs[i].SBD)==0)
					{
						cout << "SBD da ton tai, moi ban nhap lai!\n " ;
						kiemtra = false ; 
					}
				}
			}while(kiemtra==false);
	cout << "\tTen hoc sinh : ";
	cin.getline(hs1.tenHs,30);
	cout << "\tToan : " ;
	cin>>hs1.toan ; 
	cout << "\tLy  : " ;
	cin>>hs1.ly ; 
	cout << "\tHoa : " ;
	cin>>hs1.hoa ;
		n++;
	    hs[n-1]=hs1;
}

void xoa(kiemtra hs[],int &n,char k[]){
		for(int i = 0; i < n; i++)
		{	
			if(strcmp(hs[i].SBD,k)==0)
			{
				for (int j = i ; j < n ; j++)
				{
					hs[j] = hs[j + 1];
				}
				cout << "\n Da xoa thanh cong thi sinh co SBD :" << k << endl;
				break;
			}
      }
}

void luutep(kiemtra hs[],int n)
{
	cout<<" "<<endl;
	fstream f;
	f.open("D:\\chatluong.dat",ios::out);
	f<<".---------------------------------------------------------------------------------------------------------------------------------------------."<<"\n";
	f<<"|                                               DANH SACH THI SINH                                                                            |"<<endl;
	f<<"|---------------------------------------------------------------------------------------------------------------------------------------------|"<<"\n";
    f<<"|"<<"STT|"<<setw(15)<<"SBD|";
    f<<setw(20)<<"TEN HS"<<setw(12)<<"|";
    f<<setw(15)<<"TOAN"<<setw(12)<<"|";
    f<<setw(15)<<"LY"<<"|";
    f<<setw(15)<<"HOA"<<"|";
    f<<setw(15)<<"TONG DIEM"<<"|";
    f<<setw(15)<<"KET QUA"<<"|"<<endl;
    f<<"|---------------------------------------------------------------------------------------------------------------------------------------------|"<<"\n";
	for (int i=0 ; i<n ; i++)
    {
        f<<"| "<<setw(2)<<i+1<<"|";
		f<<setw(14)<<hs[i].SBD<<"|";
        f<<setw(20)<<hs[i].tenHs<<setw(12)<<"|";
        f<<setw(15)<<hs[i].toan<<setw(12)<<"|";
        f<<setw(14)<<hs[i].ly<<setw(3)<<"|";
        f<<setw(10)<<hs[i].hoa<<setw(5)<<"|";
        f<<setw(10)<<hs[i].tongdiem<<setw(5)<<"|";
        f<<setw(12)<<hs[i].ketqua<<setw(5)<<"|"<<endl;
		f<<".---------------------------------------------------------------------------------------------------------------------------------------------."<<"\n";        
    }	
	f.close();
	cout<<" "<<endl;
	cout<<"------LUU THANH CONG------\n"<<endl;
	cout<<" "<<endl;
}

void doctep(kiemtra hs[],int n,string x[])
{
cout<<" "<<endl;	
	fstream f;
	f.open("D:\\chatluong.dat",ios::in);
	for(int i = 0; i < n; i++)
	{
   	    while(!f.eof())
		{
			getline(f,x[i]);
			cout<<x[i]<<endl;		
		}	
	}
	f.close();
cout<<" "<<endl;

}
int main (){
	kiemtra hs[100];
	int luachon;
	int n;
	char k[10];
	string x[100];
 	menu();
chay :	
        cout<<"\n-*-*-*-*Nhap lua chon cua ban (0-10): ";
        cin>>luachon;
        
    	switch(luachon)
		{
   			case 1:nhap(hs,n);break;
    		case 2:{
		 			tong(hs,n);
					kq(hs,n);
					break;}
    		case 3:kq(hs,n);xuat(hs,n);break;
    		case 4:{
				kq(hs,n);
				in_dat(hs,n);
				break;
				}
    		case 5:sapxep(hs,n);break;
    		case 6:{
			       themhs(hs,n);
			       tong(hs,n);
			       kq(hs,n);
			       sapxep(hs,n);
					xuat(hs,n);      
      		break;
			       }
            case 7:
		{	cout<<"Nhap SBD thi sinh can xoa :";
			cin.ignore();
            cin.getline(k,10);
			xoa(hs,n,k);
			n--;
			xuat(hs,n);
			}
			break;
            case 8:luutep(hs,n);break;
            case 9:doctep(hs,n,x);break;
			case 0:cout<<"\n\n\n\t\t\t-----------------TAM BIET<3-----------------\n"<<endl;exit(1);break;
    		default:cout<<"Khong hop le ";
    	}
    goto chay;
    return 0;
    }
