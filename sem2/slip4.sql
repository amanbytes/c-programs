create table movie(m_name varchar(25) primary key,release_year integer,budget money);
create table actor(a_name varchar(30) primary key, role varchar(30),charges money,a_address varchar(30));
create table movie_actor(m_name varchar(25) references movie(m_name),a_name varchar(25) references actor(a_name));

insert into movie values('Spider Man',2022,200000000);
insert into movie values('KGF',2018,1000000);
insert into movie values('Multiverse 0f Madness',2022,300000000);
insert into movie values('End Game',2020,500000000);
insert into movie values('KGF2',2022,2000000);


insert into actor values('Tom Holland','Protagonist',4000000,'USA');
insert into actor values('Shubham','Hero',40000,'Malegaon');
insert into actor values('Vidikti','Heroin',60000,'Pune');
insert into actor values('Shaktivel','Villan',80000,'Karnatak');
insert into actor values('Ritik','Detective',9000,'Nashik');

insert into movie_actor values('Spider Man','Tom Holland');
insert into movie_actor values('KGF2','Shubham');
insert into movie_actor values('Spider Man','Vidikti');
insert into movie_actor values('End Game','Ritik');
insert into movie_actor values('End Game','Tom Holland');

create or replace function mdetail(mname varchar(25)) returns void as'
declare c1 cursor for select release_year, budget from movie where  m_name=mname;
release_year integer;
budget money;
begin
open c1;
loop
fetch c1 into release_year,budget;
exit when not found;
raise notice ''Release Year: %'',release_year;
raise notice ''Budget: %'',budget;
end loop;
close c1;
end'
language 'plpgsql';

sem2=# select mdetail('Spider Man');
NOTICE:  Release Year: 2022
NOTICE:  Budget: $200,000,000.00


create or replace function adetail(aname varchar(30)) returns void as'
declare c1 cursor for select m_name from movie_actor where  a_name=aname;
mname varchar(25);
begin
open c1;
loop
fetch c1 into mname;
exit when not found;
raise notice ''Movie Name: %'',mname;
end loop;
close c1;
end'
language 'plpgsql';

sem2=# select adetail('Tom Holland');                                        
NOTICE:  Movie Name: Spider Man
NOTICE:  Movie Name: End Game

create or replace function ra() returns trigger as'
begin
raise notice ''actor is deleted %'',old;
return old;
end;'
language 'plpgsql';


create or replace function maxbud() returns void as'
declare c1 cursor for select max(budget) from movie;
c2 refcursor;
m_name text;
max money;
begin
open c1;
fetch c1 into max;
close c1;
open c2 for select * from movie where budget=max;
fetch c2 into m_name;
raise notice ''M_name: %'',m_name;
end'
language 'plpgsql';
create trigger ra after delete on actor for each row execute procedure ra();