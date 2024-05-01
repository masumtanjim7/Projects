create database onlinebanking;

show databases;

use onlinebanking;

create table signup(fromno varchar(30),user_name varchar(30),father_name varchar(30),dob varchar(30), gender varchar(30), email varchar(30),marital varchar(30),address varchar(30),city varchar(30),pincode varchar(30),state varchar(30));

show tables;



select * from signup;

create table signup2(formno varchar(20), religion varchar(20), category varchar(20), income varchar(20), education varchar(20), occupation varchar(20), contact varchar(20), nidNum varchar(20), seniorcitizen varchar(20), existingaccount varchar(20));

select * from signup2;

create table signup3(fromno varchar(30),accoutType varchar(30),cardnumber varchar(30),pin varchar(30),facilities varchar(50));

select * from signup3;

create table login(formno varchar (30), cardnumber varchar (25), pinNumber varchar(20));

select * from login;

create table bank(pin varchar(10), date varchar(50), type varchar(20), amount varchar(20));

DROP table signup2;