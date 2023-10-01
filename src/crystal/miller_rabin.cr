require "big"

module Primes
	module MillerRabin

		def powIsPrime?(pow_n)

			number = BigInt.new(self)
			number = (number ** pow_n) - 1

			case number
			when 1
				return "#{number} e composto"
			when 2
				return "Provavel Primo"
			end
			if (number % 2) == 0
				return "Composto"
			end

			k, q = findKQ(number)
			#a = (number - 1) / rand(1..10000)
			a = 2071

			number_test_1 = powmod(a, q, number)
			if number_test_1 == 1 || number_test_1 == (number - 1)
				return "Provavel Primo"
			end

    	x = number_test_1
			i = 1

			while i <= k
				puts "#{i}/#{k}"
				number_test_2 = powmod(x,2,number)
				if number_test_2 == (number - 1) 
					return "Provavel Primo"
				end
				x = number_test_2
				i += 1
			end
			return "Composto"
		end

		private def findKQ(number)
    	q = number - 1
    	k = 0
    	while q % 2 == 0
      	q = q//2
      	k=k+1
			end
    	return k, q
		end
		private def powmod(b, e, m)
      r, b = 1, b.to_big_i
      while e > 0
        r = (b * r) % m if e.odd?
        b = (b * b) % m
        e >>= 1
      end
      r
    end
	end
end

struct Int; include Primes::MillerRabin end

n = 44497
puts "Number 2 ** #{n} is Prime?\nStarting timer now..."

elapse_time = Time.measure do
	puts 2.powIsPrime?(n)
end

puts "Approximately #{elapse_time}"
