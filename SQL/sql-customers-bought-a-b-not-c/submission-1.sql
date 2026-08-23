-- Write your query below
SELECT c.customer_id , c.customer_name
FROM customers c
WHERE customer_id IN (SELECT distinct(o.customer_id)
FROM orders o
WHERE o.product_name = 'A') AND customer_id IN (SELECT distinct(o.customer_id)
FROM orders o
WHERE o.product_name = 'B') AND customer_id NOT IN (SELECT distinct(o.customer_id)
FROM orders o
WHERE o.product_name = 'C')
ORDER BY c.customer_name;
