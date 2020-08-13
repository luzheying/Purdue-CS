use loginid;

CREATE TABLE Professor (   
  ProfessorID INTEGER PRIMARY KEY NOT NULL,   
  Name TEXT NOT NULL,   
  Position TEXT NOT NULL);

CREATE TABLE Department ( 
  DepartmentID INTEGER PRIMARY KEY NOT NULL,   
  Name TEXT NOT NULL,   
  Head INTEGER NOT NULL, 
  FOREIGN KEY(Head) REFERENCES Professor(ProfessorID) ON DELETE CASCADE 
);

CREATE TABLE Student (
  PUID INTEGER PRIMARY KEY NOT NULL ,
  Name TEXT NOT NULL,
  Address TEXT NOT NULL,
  Phone TEXT NOT NULL
);

CREATE TABLE TA (
  TA_PUID INTEGER PRIMARY KEY NOT NULL,
  Name TEXT NOT NULL,
  TA_Position TEXT NOT NULL,
  SSN INTEGER NOT NULL,
  Department INTEGER NOT NULL,
  FOREIGN KEY(Department) REFERENCES Department(DepartmentID) ON DELETE CASCADE
);

CREATE TABLE Professor_Affiliation (
  Professor INTEGER NOT NULL,
  Department INTEGER NOT NULL,
  PrimaryAffiliation BOOLEAN NOT NULL,
  PRIMARY KEY(Professor, Department),
  FOREIGN KEY(Professor) REFERENCES Professor(ProfessorID) ON DELETE CASCADE,
  FOREIGN KEY(Department) REFERENCES Department(DepartmentID) ON DELETE CASCADE
);

CREATE TABLE Lecture(
  LectureID INTEGER PRIMARY KEY NOT NULL,
  Student INTEGER NOT NULL,
  TA INTEGER,
  Professor INTEGER NOT NULL,
  Day TEXT NOT NULL,
  Start TIME NOT NULL,
  End TIME NOT NULL,
  FOREIGN KEY(Student) REFERENCES Student(PUID) ON DELETE CASCADE,
  FOREIGN KEY(TA) REFERENCES TA(TA_PUID) ON DELETE CASCADE,
  FOREIGN KEY(Professor) REFERENCES Professor(ProfessorID) ON DELETE CASCADE
);



