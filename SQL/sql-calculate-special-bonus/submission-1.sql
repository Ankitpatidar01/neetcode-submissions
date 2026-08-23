-- Write your query below
SELECT distinct(e.employee_id) , (CASE 
                         WHEN e.employee_id % 2 = 1 and e.name NOT LIKE 'M%' THEN e.salary ELSE 0
                         END) as bonus
FROM employees  e
ORDER BY e.employee_id;
