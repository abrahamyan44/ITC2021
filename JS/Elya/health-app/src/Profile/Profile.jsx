import React from 'react';
import {Avatar, Card, CardContent, H4, ListItem} from 'ui-neumorphism';
import Navigation from '../componenets/Navigation/Navigation';
import Icon from '@mdi/react';
import {
    mdiAccount
} from '@mdi/js';
import './Profile.css'


function Food(props) {
    return(
        <>
            <Card rounded width={340} height={610} className='card'>
                <CardContent>
                <H4 className='profile-card-title'>Profile</H4>
                <Avatar
                size={120}
                className='avatar'
                >
                    <Icon path={mdiAccount} size={3} />
                </Avatar>
                <Card
                    flat
                    width={300}
                    className='d-flex align-center justify-center flex-wrap'
                    >
                    <ListItem
                        link
                        active
                        title='Name'
                        subtitle='Aram'
                    />
                    <ListItem
                        link
                        active
                        title='Last Name'
                        subtitle='Aramyan'
                    />
                    <ListItem
                        link
                        active
                        title='Age'
                        subtitle='23'
                    />
                    <ListItem
                        link
                        active
                        title='Weight'
                        subtitle='80kg'
                    />
                </Card>
                </CardContent>
                <Navigation />
            </Card>
        </>
    )
} 

export default Food;