Consider the following database
Student (roll_no integer, name varchar(30), address varchar(50), class varchar(10))
Subject (scode varchar(10), subject_name varchar(20))
Student-Subject are related with M-M relationship with attributes marks_scored.

Create the above database in PostGreSQL and insert sufficient records.
Execute any two of the following using PL/pgSQL



iii. Write a trigger which is executed when insertion is made in the
student-subject table. If marks_scored is less than 0, give
appropriate message and do not allow the insertion. 

Q A]
create table student(rollno integer primary key,stud_name varchar(20),adress varchar(20),class varchar(20));
insert into student values(1,'Aman','Nashik','FYBCS');
insert into student values(2,'Ritik','Nashik','FYBCS');
insert into student values(3,'Radhika','Nashik','FYBCS');
insert into student values(4,'Ashirwad','Pune','SYBCS');
insert into student values(5,'Prafull','Nashik','TYBCS');

create table subject(scode integer primary key,subject_name varchar(20));
insert into subject values(101,'C_Programing');
insert into subject values(102,'DBMS');
insert into subject values(103,'RDBMS');
insert into subject values(104,'JAVA');
insert into subject values(105,'PHP');

create table stud_sub(rollno integer references student(rollno),scode integer references subject(scode),marks_scored integer);
insert into stud_sub values(1,101,50);
insert into stud_sub values(2,102,55);
insert into stud_sub values(3,103,65);
insert into stud_sub values(4,104,75);
insert into stud_sub values(5,105,85);

Q B]
i) Write a function which will accept the roll no and print all the
details of that student.


create or replace function f1(no integer) returns void as'
declare c1 cursor for select stud_name,adress,class from student where rollno=no;
stud_name text;
adress text;
class text;
begin
open c1;
loop
fetch c1 into stud_name,adress,class;
exit when not found;
raise notice ''student name:%'',stud_name;
raise notice ''student adress:%'',adress;
raise notice ''student class:%'',class;
end loop;
close c1;
end '
language 'plpgsql';

CREATE FUNCTION

to execute function  use command

db1=# select f1(1);
NOTICE:  student name:Aman
NOTICE:  student adress:Nashik
NOTICE:  student class:FYBCS
 f1 
----
 
(1 row)

db1=# select f1(2);
NOTICE:  student name:Ritik
NOTICE:  student adress:Nashik
NOTICE:  student class:FYBCS
 f1 
----
 
(1 row)

ii) Write a function using cursor which will accept the name of the
subject and print the roll_no, name and marks of all students for
that subject.

create or replace function f11(sname varchar(20)) returns void as'
declare c3 cursor for select student.rollno,student.stud_name,stud_sub.marks_scored from student,stud_sub,subject where student.rollno=stud_sub.rollno and subject.scode=stud_sub.scode and subject_name=sname;
rollno integer;
stud_name varchar(20);
marks_scored integer;
begin
open c3;
loop
fetch c3 into rollno,stud_name,marks_scored;
exit when not found;
raise notice ''Student Roll No:%'',rollno;
raise notice ''Student Name:%'',stud_name;
raise notice ''student Marks:%'',marks_scored;
end loop;
close c3;
end '
language 'plpgsql';

db1=# select f11('JAVA');
NOTICE:  Student Roll No:4
NOTICE:  Student Name:Ashirwad
NOTICE:  student Marks:75
 f11 
-----
 
(1 row)



iii) Write a trigger which is executed when insertion is made in the
student-subject table. If marks_scored is less than 0, give
appropriate message and do not allow the insertion. 



create or replace function f22()returns trigger as'
begin
if new.marks_scored =''0'' then
raise exception''Zero Marks not allowed %'',new;
end if;
return new;
end 
'language 'plpgsql';

//trigger
[root@localhost data]# vi item_trigger2.sql
create trigger t10 before insert on stud_sub for each row execute procedure f22();

//output:
item-supplier=# \i item_pro2.sql
CREATE FUNCTION
item-supplier=# \i item_trigger3.sql
CREATE TRIGGER
item-supplier=# insert into item_sup values(1,102,'0');
ERROR:  Zero rate not allowed
item-supplier=# update item_sup set rate='0' where itemno=1;
ERROR:  Zero rate not allowed
//****************








