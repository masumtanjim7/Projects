create database onlinebanking;

show databases;

use onlinebanking;

create table signup(formno varchar(30),User_Name varchar(30),Father_Name varchar(30),DateOfBirth varchar(30), Gender varchar(30), Email varchar(30), Marital varchar(30),Address varchar(30),City varchar(30),Pincode varchar(30),State varchar(30));

show tables;



select * from signup;

create table signup2(formno varchar(20), Religion varchar(20), Category varchar(20), Income varchar(20), Education varchar(20), Occupation varchar(20), Contact varchar(20), NidNum varchar(20), SeniorCitizen varchar(20), ExistingAccount varchar(20));

select * from signup2;

create table signup3(fromno varchar(30),AccoutType varchar(30),cardnumber varchar(30),pin varchar(30),Facilities varchar(50));

select * from signup3;

create table login(formno varchar (30), cardnumber varchar (25), pinNumber varchar(20));

select * from login;

create table bank(pin varchar(10), date varchar(50), type varchar(20), amount varchar(20));

DROP table bank;

select * from bank;