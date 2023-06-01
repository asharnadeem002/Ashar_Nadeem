
--Project Members
-- Abdullah Awais 21L-7620
-- Furqaan Ahmad 21L-1765
-- Ashar Nadeem 21L-5336
-- Murtaza Ahmed 20L-0954

Create table [USER]
(
  UserID int primary key,
  UserName varchar(20)Not Null unique,
  state varchar(20) Not Null,
  City varchar(20)Not Null,
  Gender varchar(7),
  Age varchar(5),
  Phone_No varchar(20)Not Null,
)


Create table Station
(
  StationNo int,
  Station_Name varchar(50) primary key Not Null,
)



Create table TrainTracking
(
  TrainID int FOREIGN KEY REFERENCES Train(TrainID) 
)


Create table Train
(
  TrainID int primary key,
  Train_Name varchar(20)Not Null,
  ArrivalTime smalldatetime Not Null,
  DepartureTime smalldatetime Not Null,
  From_Station varchar(50),
  To_Station varchar(50),
 
)

INSERT INTO [Train] ([TrainID],[Train_Name],[From_Station],[To_Station],[ArrivalTime],[DepartureTime]) 
VALUES 
(10001,'Awaam Exprees','Peshawar Cantt','Lahore JN', '2023-12-13 12:45:00','2023-12-13 13:15:00'),
(10002,'Karakarom Exprees','Karachi Cantt', 'Gujrat','2023-12-23 03:00:00','2023-12-13 03:15:00'),
(10003,'Pakistan Exprees','Rawalpindi','Faisalabad', '2024-01-01 22:30:00','2024-01-01 23:00:00'),
(10004,'Shalimar Exprees','Lahore JN.','Karachi Cantt', '2024-01-09 11:45:00','2024-01-09 12:15:00'),
(10005,'Jinnah Exprees','Jacobabad JN.','Peshawar Cantt', '2024-01-12 02:45:00','2024-01-12 03:15:00')  
Go

Create table TrainStatus
(
  TrainID int FOREIGN KEY REFERENCES Train(TrainID),
  BerthFare int Not Null,
  SeatFare int Not Null,
  Class varchar(20) Not Null
)

INSERT INTO [TrainStatus] ([TrainID],[Class],[SeatFare],[BerthFare]) 
VALUES 
(10001,'AC Standard',5000,6500),
(10001,'AC Business',7000,8500),
(10001,'AC Sleeper',9000,10500),
(10001,'Economy',3000,3500),

(10002,'AC Standard',5000,6500),
(10002,'Economy',3000,3500),

(10003,'AC Standard',5000,6500),
(10003,'AC Sleeper',9000,10500),
(10003,'Economy',3000,3500),

(10004,'AC Business',7000,8500),
(10004,'AC Sleeper',9000,10500),
(10004,'Economy',3000,3500),

(10005,'Economy',3000,3500)
  
Go



INSERT INTO [Ticket] ([TicketID],[Status],[TrainNo],[UserID],[Age],[Fare]) 
VALUES 
(100,10001,10,'Ahmad',13,'Awaam Exprees','Peshawar Cantt','Lahore JN', '2023-12-13 12:45:00','2023-12-13 13:15:00'),
(101,10002,11,'Bilal',19,'Karakarom Exprees','Karachi Cantt', 'Gujrat','2023-12-23 03:00:00','2023-12-13 03:15:00'),
(102,10003,12,'Furqaan',20,'Pakistan Exprees','Rawalpindi','Faisalabad', '2024-01-01 22:30:00','2024-01-01 23:00:00'),
(103,10004,13,'Ashar',25,'Shalimar Exprees','Lahore JN.','Karachi Cantt', '2024-01-09 11:45:00','2024-01-09 12:15:00'),
(104,10005,14,'Abdullah',30,'Jinnah Exprees','Jacobabad JN.','Peshawar Cantt', '2024-01-12 02:45:00','2024-01-12 03:15:00')  
Go


Create table Passenger
(
  passengerID int primary key,
  UserID int FOREIGN KEY REFERENCES [USER](UserID),
  Name varchar(20)Not Null,
  City varchar(20)Not Null,
  Gender varchar(7)check(Gender = 'Male' or Gender = 'Female'),
  Age varchar(5),
  BookingDate date,
  TicketID int FOREIGN KEY REFERENCES Ticket(TicketID),
)

INSERT INTO [Passenger] ([passengerID],[UserID],[Name],[SeatNo],[City],[Gender]) 
VALUES 
(10001,'Awaam Exprees','Peshawar Cantt','Lahore JN', '2023-12-13 12:45:00','2023-12-13 13:15:00'),
(10002,'Karakarom Exprees','Karachi Cantt', 'Gujrat','2023-12-23 03:00:00','2023-12-13 03:15:00'),
(10003,'Pakistan Exprees','Rawalpindi','Faisalabad', '2024-01-01 22:30:00','2024-01-01 23:00:00'),
(10004,'Shalimar Exprees','Lahore JN.','Karachi Cantt', '2024-01-09 11:45:00','2024-01-09 12:15:00'),
(10005,'Jinnah Exprees','Jacobabad JN.','Peshawar Cantt', '2024-01-12 02:45:00','2024-01-12 03:15:00')  
Go



Create table BookedTickects
(
  TicketID int FOREIGN KEY REFERENCES Ticket(TicketID),
  passengerID int FOREIGN KEY REFERENCES Passenger(passengerID),
)

Create table CancelBooking
(
  TicketID int FOREIGN KEY REFERENCES Ticket(TicketID),
  passengerID int FOREIGN KEY REFERENCES Passenger(passengerID),
  UserID int FOREIGN KEY REFERENCES [USER](UserID)
)


Select * from Train
Select * from TrainStatus


Go
create procedure checkfare
@FromStationName varchar(30),
@ToStationName varchar(30),
@Found int output

/*declare @F int
exec 
Searchtrain 'chennai',
@found=@F output

select @f*/
AS
SeLect t.Train_Name,t.From_Station,t.To_Station,ts.Class,ts.BerthFare,ts.SeatFare
From Train t inner join TrainStatus ts on t.TrainID=ts.TrainID 
Where t.From_Station=@FromStationName and t.To_Station=@ToStationName

if @@ROWCOUNT>0 --item found
set @Found=1
else 
set @Found=0




/*go
create Procedure TickectBooked
  @trainNO int,
  @username varchar(50) ,
  @age int,
 @tranname varchar(20) ,
 @fromstation  varchar(50),
 @tostation varchar(50) ,
 @date varchar(20) ,
 @class  varchar(20) ,
 @totaltickects varchar(20) ,
   @email_Exists int output,
  @userName_Exists int output,
  @found int output
 

as
begin
declare @trainID int
set @trainID=(select TrainID from Train where Train_Name=@tranname)
set  @email_Exists=0
set    @userName_Exists=0

if(@userName_Exists =0 AND @email_Exists=0 )
begin
insert into TicketBooking values 
(@trainID,@username,@age,@tranname,@fromstation,@tostation,@date,@class,@totaltickects)
end
if(@@ROWCOUNT>0)
	begin
		set @found=1
	end
else
	begin
		set @found=0
	end
end
*/




Create table Tbook
(

  UserName varchar(20)Not Null unique,
  Age varchar(5),
  Train_Name varchar(20)Not Null,
  From_Station varchar(50),
  To_Station varchar(50),
  Selectdate varchar(20),
  Class varchar(20) Not Null,
  TotalTickects int,

)



go
Create Procedure Buyer_SignupProcedure
  
 @username varchar(50) ,
 @age int,
 @tranname varchar(20) ,
 @fromstation  varchar(50),
 @tostation varchar(50) ,
 @date varchar(20) ,
 @class  varchar(20) ,
 @totaltickects varchar(20) ,

 @email_Exists int output,
 @userName_Exists int output,
 @found int output
 

as
begin
set  @email_Exists=0
set    @userName_Exists=0
if exists(select t.Train_Name
                from Train t
				 where  t.Train_Name=@tranname )
		begin
			set  @email_Exists=1
			
		end
if exists(select t.Train_Name
                from Train t
				 where  t.Train_Name=@tranname  )
		begin
			set    @userName_Exists=1
		
		end


if(@userName_Exists =0 AND @email_Exists=0 )
begin
Insert into Tbook
Values(@username,@age,@tranname,@fromstation,@tostation,@date,@class,@totaltickects)

end

if(@@ROWCOUNT>0)
	begin
		set @found=1
	end
else
	begin
		set @found=0
	end
end










