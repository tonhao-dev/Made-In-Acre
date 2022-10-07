// https://www.beecrowd.com.br/judge/pt/questions/view/1487/9929
// Problema da mochila, permite repetição de itens, PD
// Na linha 180 uma função com o problema da mochila classico
#include <iostream>
#include <vector>

#define lld long long int

using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

class UnboundedKnapsack
{
    //-------------------------------------------------------------------------
    //		Attributes
    //-------------------------------------------------------------------------
    /**
     * Stores maximum value of the knapsack for a certain capacity.
     */
    std::vector<int> knapsack;

    /**
     * Stores elements that are part of the knapsack with a certain capacity.
     * <li><b>Line:</b> Knapsack capacity</li>
     * <li><b>Column:</b> Elements</li>
     */
    std::vector<std::vector<int>> selectedElements;

    /**
     * Stores maximum knapsack capacity.
     */
    int maximumCapacity;

public:
    //-------------------------------------------------------------------------
    //		Constructor
    //-------------------------------------------------------------------------
    UnboundedKnapsack()
    {
        maximumCapacity = -1;
    }

    //-------------------------------------------------------------------------
    //		Destructor
    //-------------------------------------------------------------------------
    ~UnboundedKnapsack()
    {
        delete this;
    }

    //-------------------------------------------------------------------------
    //		Methods
    //-------------------------------------------------------------------------
    /**
     * Unbounded knapsack allows to use one or more occurrences of an item.
     *
     * @param		w Weight of the elements
     * @param		v Value of the elements
     * @param		N Number of itens
     * @param		W Maximum weight capacity
     * @return		This object to allow chained calls
     */
    UnboundedKnapsack *knapsack_unbounded(std::vector<lld> &w, std::vector<lld> &v, lld N, lld W)
    {
        // Stores the maximum value which can be reached with a certain capacity
        knapsack.clear();
        knapsack.resize(W + 1);

        maximumCapacity = W + 1;

        // Stores selected elements with a certain capacity
        selectedElements.resize(W + 1);

        // Initializes maximum value vector with zero
        for (lld i = 0; i < W + 1; i++)
        {
            knapsack[i] = 0;
        }

        // Computes the maximum value that can be reached for each capacity
        for (lld capacity = 0; capacity < W + 1; capacity++)
        {
            // Goes through all the elements
            for (lld n = 0; n < N; n++)
            {
                if (w[n] <= capacity)
                {
                    // max(knapsack[capacity], knapsack[capacity - w[n]] + v[n])
                    if (knapsack[capacity] <= knapsack[capacity - w[n]] + v[n])
                    {
                        knapsack[capacity] = knapsack[capacity - w[n]] + v[n];

                        // Stores selected elements
                        selectedElements[capacity].clear();
                        selectedElements[capacity].push_back(n + 1);

                        for (lld elem : selectedElements[capacity - w[n]])
                        {
                            selectedElements[capacity].push_back(elem);
                        }
                    }
                }
            }
        }

        return this;
    }

    /**
     * Returns maximum value for a certain number of elements and a certain
     * capacity.
     *
     * @param		capacity Capacity of the knapsack
     * @return		Maximum possible value with capacity provided
     * @throws		std::invalid_argument If capacity provided is out of bounds
     */
    int getMaximumValue(int capacity)
    {
        if (capacity < 0 || capacity >= maximumCapacity)
            throw std::invalid_argument("Capacity out of bounds");

        return knapsack[capacity];
    }

    /**
     * Returns elements that belong to the knapsack with a certain capacity.
     *
     * @param		capacity Capacity of the knapsack
     * @return		Elements that are part of the knapsack with the capacity
     * provided
     * @throws		std::invalid_argument If capacity provided is out of bounds
     * @apiNote		Elements are referenced by their index + 1
     */
    std::vector<int> &getSelectedElements(int capacity)
    {
        if (capacity < 0 || capacity >= maximumCapacity)
            throw std::invalid_argument("Capacity out of bounds");

        return selectedElements[capacity];
    }

    /**
     * Returns elements that are part of the knapsack with a certain capacity.
     * This method will return a {@link std::string} with the following format:
     * <code>[elem1, elem2, elem3...]</code>
     *
     * @param		capacity Capacity of the knapsack
     * @return		Elements that are part of the knapsack with the capacity
     * provided
     * @apiNote		Elements are referenced by their index + 1
     */
    std::string selectedElements_toString(int capacity)
    {
        std::string response = "[";

        for (int element : selectedElements[capacity])
        {
            response.append(std::to_string(element));
            response.append(", ");
        }

        // Removes last ", "
        response.pop_back();
        response.pop_back();

        response.append("]");

        return response;
    }
};
// Problema da mochila classico, temos n itens
// com W capacidade, wt é um array de peso de cada item
// val um array com o valor de cada item
// maximizamos o valor maximo dado a nossa capacidade
// Returns the maximum value that
// can be put in a knapsack of capacity W
lld knapSack(lld W, lld wt[], lld val[], lld n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1],
                                  wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
    lld instancia = 1;
    lld num_itens, capacidade;

    while (cin >> num_itens >> capacidade)
    {
        if (num_itens == 0 && capacidade == 0)
            break;

        vector<lld> peso_item(num_itens);
        vector<lld> valor_item(num_itens);

        for (lld i = 0; i < num_itens; i++)
            cin >> peso_item[i] >> valor_item[i];

        lld posicao_ultimo_item = num_itens - 1;

        cout << "Instancia " << instancia << endl;

        UnboundedKnapsack *knapsack = new UnboundedKnapsack();
        knapsack->knapsack_unbounded(peso_item, valor_item, num_itens, capacidade);

        cout << knapsack->getMaximumValue(capacidade) << endl
             << endl;

        instancia++;
    }

    return 0;
}
