#pragma once
#include <algorithm>
#include <vector>
#include <tuple>
#include <iterator>
#include <optional>
#include <iostream>

/**
 * @brief Container used to store assoicate keys with values.
 * values can later be retrived using the corresponding key.
 * 
 * @tparam K type of the keys stored in the dictionary.
 * @tparam V type of the values assoicated with each key.
 */
template <class K, class V>
class Dict
{
private:
    std::vector<K> keys_;
    std::vector<V> val_;

public:
    /**
     * @brief Associates the key with the specified value.
     * If the key is already in the dictionary its value is overwritten.
     * 
     * @param key key associated with the provided key.
     * @param val value assoicated with the provided key.
     */
    void set(K key, V val)
    {
        // check if key is in dictionary
        std::cout << "checking if " << key << " is already in dictionary....\n";

        // loop through dictionary log position via itterator int i
        for (int i = 0; i < keys_.size(); i++) {
            // if found overwrite value
            if (keys_[i] == key) {
                std::cout << key << " already in dictionary, overwriting " << val_[i] << " with " << val << "\n";
                val_[i] = val;
                return;
            }
        }

        // add key to list of keys along with val to list of values
        std::cout << key << " not found in dictionary, adding " << key << " to dictionary...\n";
        keys_.push_back(key);
        val_.push_back(val);

        // confirm whether it succesfully added the key
        if (!has(key))
        {
            std::cout << "failed to add " << key << " to dictionary\n";
            return;
        }
        std::cout << key << " added to dictionary\n";
    }

    /**
     * @brief Determines if the key is defined in the dictionary.
     * 
     * @param key key for which to look for.
     * @return true if the key is defined in the dictionary.
     * @return false otherwise.
     */
    bool has(K key) const
    {
        // loop through the keys vector and if key matches return true
        for (int i = 0; i < keys_.size(); i++) {
            if (keys_[i] == key) {
                return true;
            }
        }

        // base case return false
        return false;
    }

    /**
     * @brief Returns the number of items in the dictionary.
     * 
     * @return the number of items in the dictionary.
     */
    size_t len()
    {
        std::cout << "Length of dictionary: " << keys_.size() << "\n";
        // use vector class size function
        return keys_.size();
    }

    /**
     * @brief Get the value associated with the specified key.
     * If no value is found std::nullopt is returned.
     * 
     * @param key key for which to locate value.
     * @return value associated with key.
     */
    std::optional<V> get(K key) const
    {
        std::cout << "checking for " << key << " in dictionary....\n";
        // loop through vector and return value if found
        for (int i = 0; i < keys_.size(); i++) {
            if (keys_[i] == key) {
                std::cout << key << " found!\n";
                return val_[i];
            }
        }

        // if not found return nullopt
        std::cout << "key not in dictionary\n";
        return std::nullopt;
    }

    /**
     * @brief Delete the specified key and its associated value
     * from the dictionary.
     * If the key is not present in the dictionary, nothing happens.
     * 
     * @param key A key currently present in the dictionary
     * which will be deleted.
     */
    void del(K key)
    {
        // these messages are potentially unneeded overhead but I am practicing adding
        // these types for user clarity. Can easily be removed for potential reduciton
        // in overhead if needed

        // loops through the key list
        for (int i = 0; i < keys_.size(); i++) {
            if (keys_[i] == key) {
                std::cout << key << " found removing from dictionary....\n";

                // using erase to remove and shrink dictionary
                keys_.erase(keys_.begin()+i);
                val_.erase(val_.begin()+i);

                // check if removed succesfully
                if (!(has(key))) {
                    std::cout << key << " removed successfully!\n";
                    return;
                }
                // in case not inform user
                std::cout << key << "failed to remove key\n";
                return;
            }
        }
        // inform user that key is not in dictionary
        std::cout << key << " not in dictionary\n";
    }

    /**
     * @brief List all keys of the dictionary.
     * 
     * @return vector of keys.
     */
    std::vector<K> keys()
    {
        std::cout << "Current keys in the dictionary:\n";
        for (int i = 0; i < keys_.size(); i++) {
            std::cout << keys_[i] << "\n";
        }
        // again not needed but added for user clarity, can be removed if needed for reduction in overhead

        // we have our vector of just keys already so just return it
        return keys_;

        // if I went with the linked list implementation I would have had to make a new vector for it
    }

    /**
     * @brief List all values of the dictionary.
     * 
     * @return vector of values.
     */
    std::vector<V> values()
    {
        std::cout << "Current values in the dictionary:\n";
        for (int i = 0; i < val_.size(); i++) {
            std::cout << val_[i] << "\n";
        }

        // we have our vector of just values already so just return it
        return val_;
    }
};