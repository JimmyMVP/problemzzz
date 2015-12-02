
ARGV[0] = "6"

number_of_nodes = ARGV[0].to_i

class FastMat

	def initialize(binary, number_of_nodes)
		@binary = binary
		@number_of_nodes = number_of_nodes
	end

	def [](i,j)
		
		if i == j
			return false
		end

		max = [i,j].max
		min = [i,j].min
		begin
			return @binary[max*max/2 + max%2 * (max+1)/2 + min] == "1"
		rescue
			return false
		end
	end

	def set_connection!(i,j)
		max = [i,j].max
		min = [i,j].min

		index = max*max/2 + max%2 * (max+1)/2 + min

		if index > @binary.length
			@binary = @binary + "0" * (index - @binary.length) 

		@binary[index] = "1"

	end

	def len()

		len = 0
		for c in @binary
			if c == "1"
				len+=1
			end
		end
		return len
	end


	def remove_connection(i,j)
		@binary[max*max/2 + max%2 * (max+1)/2 + min] = "0"
	end

end
graphs = []

edge_matrix = Array.new(number_of_nodes){Array.new(number_of_nodes,false)}

##Generate graphs
graph = edge_matrix


def is_almost_euler(graph)
	for i in (0..number_of_nodes)
	start_node = graph.get_connection(i)
	if start_node >= 0
		break
	end

	path = []
	clo = graph.clone 
	while true

		for i in (0..number_of_nodes)
			if graph[start_node, i]
				path.push([start_node, i])
				break
			if i == number_of_nodes && path.length != 0


	end
end

for num in (0..2**(number_of_nodes*(number_of_nodes-1))/2-1) 
	num_s = num.to_s(2)
	edges = {}
	path = [] 
	graph = FastMat.new("1110", number_of_nodes)


	

	break
end





## i = starting node
## j = ending node + 1












