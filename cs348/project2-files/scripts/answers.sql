use loginid; -- replace with your Purdue username
DELIMITER $$

-- Fill the Procedure
DROP PROCEDURE IF EXISTS TA_NAMES;
CREATE PROCEDURE TA_NAMES(IN prof_id INT)
BEGIN
	
END$$

DELIMITER ;

CALL TA_NAMES (1007);

DELIMITER $$

-- Fill the Function
DROP FUNCTION IF EXISTS DEPT_DETAIL;
CREATE FUNCTION DEPT_DETAIL(dept_id INT) RETURNS INT
BEGIN
	
END$$

DELIMITER ;

 -- Call this function within a Query.Eg: Select * from Professor where ProfessorID = DEPT_DETAIL(2)<-- Use the same argument(2) to invoke the Function;




