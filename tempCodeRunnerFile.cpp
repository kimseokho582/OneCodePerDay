
            if (isFisrt)
            {
                ans = i - 4000;
                isFisrt = false;
            }
        }
        if (table[i] > most)
        {
            most = table[i];
            ans = i - 4000;
            isFisrt = true;
        }
    }