-- Write your query below
SELECT distinct(c.customer_id)
FROM customers c
WHERE c.revenue > 0 and c.year = '2020';