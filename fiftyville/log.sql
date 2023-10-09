-- find the description of the crime scene
 SELECT description
   ...> FROM crime_scene_reports
   ...> WHERE day = 28
   ...> AND month = '7'
   ...> AND year = 2021
   ...> AND street = 'Humphrey Street'
   ...> ;

-- description: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- Littering took place at 16:36. No known witnesses.



-- to find the transcript of the witness
 SELECT transcript
   ...> FROM interviews
   ...> WHERE month = '7'
   ...> AND day = 28
   ...> AND year = 2021
   ...> ;


--transcript: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want ttakeo look for cars that left the parking lot in that time frame.                                                          |
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to  the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |





-- to see the activity and licence from the security logs
SELECT activity,minute,license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;

--data found:
--activity | minute | license_plate |
--+----------+--------+---------------+
--| exit     | 16     | 5P2BI95       |
--| exit     | 18     | 94KL13X       |
--| exit     | 18     | 6P58WS2       |
--| exit     | 19     | 4328GD8       |
--| exit     | 20     | G412CB7       |
--| exit     | 21     | L93JTIZ       |
--| exit     | 23     | 322W7JE       |
--| exit     | 23     | 0NTHK55       |





-- i used all the licenses found to look for the names in the peoples table to make a list of suspects
 SELECT name FROM people WHERE license_plate IN(SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 24 AND minute > 15);

 --suspects:
--| Vanessa |
--| Barry   |
--| Iman    |
--| Sofia   |
--| Luca    |
--| Diana   |
--| Kelsey  |
--| Bruce   |


--next i searched for the accounts number of all the people that withdrawed money from the legget street atm on the day of the theft
SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

--result:
--| account_number |
--+----------------+
--| 28500762       |
--| 28296815       |
--| 76054385       |
--| 49610011       |
--| 16153065       |
--| 25506511       |
--| 81061156       |
--| 26013199       |



--found the name of the people related to the account_numbers
SELECT name FROM people WHERE id IN(SELECT person_id FROM bank_accounts WHERE account_number IN(SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND at
m_location = 'Leggett Street' AND transaction_type = 'withdraw'))


--names:
--|  name   |
--+---------+
--| Kenny   |
--| Iman    |
--| Benista |
--| Taylor  |
--| Brooke  |
--| Luca    |
--| Diana   |
--| Bruce


--updated suspects:
--iman
--diana
--bruce


--looking at the persons who made phone calls of less than a minute in the day of the theft, i found that only diana and bruce did that, also found the people who the called who is the accomplice
 SELECT receiver FROM phone_calls WHERE caller IN (SELECT phone_number FROM people WHERE name = 'Bruce' or name = 'Diana' or name = 'Iman') AND year = 2021 AND month = 7 AND day = 28 AND duration <60;

--reciever:
--|    receiver    |
--+----------------+
--| (375) 555-8161 |
--| (725) 555-3243 |




--found the names of the suspects of accomblice using the phone numbers that i found on the previous step

--|  name  |
--+--------+
--| Philip |
--| Robin  |


-- to find the flight that the thief took i looked for the earliest one the day after the theft
SELECT * FROM flights WHERE origin_airport_id =(SELECT id FROM airports WHERE city = 'Fiftyville') AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour,minute LIMIT 1


--| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
--+----+-------------------+------------------------+------+-------+-----+------+--------+
--| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |




-- using the passengers table i looked if either bruce or diana was on that plane, doing that i found that indeed bruce was in that plane and diana wasnt wich means that bruce is the thief
SELECT seat FROM passengers WHERE passport_number =(SELECT passport_number FROM people WHERE name = 'Bruce') AND flight_id = 36;

--thief: bruce


--knowing that i also know who the accomplice was
 SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE caller IN (SELECT phone_number FROM people WHERE name = 'Bruce') AND year = 2021 AND month = 7 AND day = 2
8 AND duration <60);

--accomplice: robin



--looking at the plans destination i found wich city the thief was going
SELECT city FROM airports WHERE id =(SELECT destination_airport_id FROM flights WHERE origin_airport_id =(SELECT id FROM airports WHERE city = 'Fiftyville') AND year = 2021 AND month = 7 AND
day = 29 ORDER BY hour,minute LIMIT 1);

--|     city      |
--+---------------+
--| New York City |