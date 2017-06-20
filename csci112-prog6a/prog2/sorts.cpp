
sorts::sorts()
{
    sortmode = SortType::BUBBLE; //default mode
    compares = 0;
    copies = 0;
    start = clock();
    finish = start;
    sorted = false;
}

sorts::sorts(SortType flag)
{
    sortmode = flag;
    compares = 0;
    copies = 0;
    start = clock();
    finish = start;
    sorted = false;
}

sorts::sorts(vector<double> a, SortType flag = SortType::BUBBLE)
{
    sorts::reset(a, flag);
}

void sorts::setmode(SortType flag)
{
    sortmode = flag;
}

bool sorts::isSorted()
{
    return sorted;
}

void sorts::sort()
{
    switch (sortmode)
    {
    case sorts::SortType::BUBBLE:
        bubble();
        break;
    case sorts::SortType::IMPROVED_BUBBLE:
        imp_bubble();
        break;
    case sorts::SortType::INSERTION:
        insertion();
        break;
    case sorts::SortType::SELECTION:
        selection();
        break;
    case sorts::SortType::QUICK:
        sorts::start = clock();
        sorts::quick(0, sorts::dataset.size() - 1);
        sorts::finish = clock();
        break;
    }
    sorts::sorted = true;
}

void sorts::swapem(double &a, double &b)
{
    double temp;
    temp = a;
    a = b;
    b = temp;
    sorts::copies += 3;
}

void sorts::bubble()
{
    int n = dataset.size();
    sorts::start = clock();
    for (int j = 0; j < n - 1; j++)
        for (int i = 0; i < n - 1; i++)
        {
            sorts::compares++;
            if (sorts::dataset[i] > sorts::dataset[i + 1])
                sorts::swapem(sorts::dataset[i], sorts::dataset[i + 1]);
        }
    sorts::finish = clock();
}

void sorts::imp_bubble()
{
    int i = 1, j, n = dataset.size();
    bool sorted = false;
    start = clock();
    while (!sorted)
    {
        sorted = true;
        for (j = 0; j < n - i; j++)
        {
            compares++;
            if (dataset[j] > dataset[j + 1])
            {
                sorted = false;
                swapem(dataset[j], dataset[j + 1]);
            }
        }
        i++;
    }
    finish = clock();
}

void sorts::selection()
{
    int small, n = sorts::dataset.size();
    sorts::start = clock();
    if (n > 1)
    {
        for (int k = 0; k < n - 1; k++)
        {
            small = k;
            for (int l = k + 1; l < n; l++)
            {
                sorts::compares++;
                if (sorts::dataset[l] < sorts::dataset[small])
                    small = l;
            }
            if (k != small)
                sorts::swapem(sorts::dataset[k], sorts::dataset[small]);
        }
    }
    sorts::finish = clock();
}

void sorts::insertion()
{
    int n = sorts::dataset.size();
    sorts::start = clock();
    int j;
    //double save;
    for (int k = n - 1; k >= 0; k--)
    {
        j = k + 1;
        while (j < n && dataset[j] < dataset[j - 1])
        {
            compares++;
            swapem(dataset[j], dataset[j - 1]);
            j++;
        }
    }
    /*
    for (k = n - 1; k >= 0; k--)
    {
        j = k + 1;
        save = dataset[k];
        dataset[n + 1] = save;
        while (save > dataset[j])
        {
            dataset[j - 1] = dataset[j];
            j++;
        }
        dataset[j - 1] = save;
    }*/
    sorts::finish = clock();
}

void sorts::quick(int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        double pivot = dataset[(left + right) / 2];
        while (i <= j)
        {
            while (dataset[i] < pivot)
            {
                i++;
                sorts::compares++;
            }
            while (dataset[j] > pivot)
            {
                j--;
                sorts::compares++;
            }
            if (i <= j)
            {
                sorts::swapem(sorts::dataset[i], sorts::dataset[j]);
                i++;
                j--;
            }
        }
        if (left < j)
            sorts::quick(left, j);
        if (i < right)
            sorts::quick(i, right);
    }
}

void sorts::reset(vector<double> a, SortType flag)
{
    dataset = a;
    sortmode = flag;
    compares = 0;
    copies = 0;
    start = clock();
    finish = start;
    sorted = false;
}

istream &operator>>(istream &is, sorts &a)
{
    double temp;
    is >> temp;
    a.dataset.push_back(temp);
    return is;
}

ostream &operator<<(ostream &os, sorts &a)
{
    os << left;
    switch (a.sortmode)
    {
    case sorts::SortType::BUBBLE:
        os << "Bubble Sort: ";
        break;
    case sorts::SortType::IMPROVED_BUBBLE:
        os << "Improved Bubble Sort: ";
        break;
    case sorts::SortType::INSERTION:
        os << "Insertion Sort: ";
        break;
    case sorts::SortType::QUICK:
        os << "Quick Sort: ";
        break;
    case sorts::SortType::SELECTION:
        os << "Selection Sort: ";
        break;
    }
    os << endl
       << "N = " << a.dataset.size() << endl;
    os << setw(6) << "";
    for (unsigned int i = 0; i < a.dataset.size(); i += (a.dataset.size() > 1) ? (a.dataset.size() / 10) : 1)
    //print every n/10th element unless N <= 1
    {
        if (i == (a.dataset.size() / 2))
            os << endl
               << setw(6) << ""; //breakline halfway through dataset
        os << left << setw(14) << a.dataset[i];
    }
    os << endl
       << endl
       << setw(6) << "";
    os << right << setw(20) << "Number of Compares = " << setw(15) << left << a.compares
       << right << setw(20) << "Number of Moves = " << setw(15) << left << a.copies
       << endl;
    os << endl
       << setw(6) << "";
    os << right << setw(20) << "Compares per N = " << setw(15) << left << (a.compares / a.dataset.size())
       << right << setw(20) << "Moves per N = " << setw(15) << left << (a.copies / a.dataset.size())
       << endl;
    os << endl
       << setw(6) << "";
    os << right << setw(20) << "Time elapsed = " << setw(10)
       << left << (a.finish - a.start) / (double)(CLOCKS_PER_SEC / 1000) << "ms" << endl
       << endl;
    return os;
}
