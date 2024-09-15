import React from 'react';
import {Card, CardContent,  H4} from 'ui-neumorphism';
import Navigation from '../componenets/Navigation/Navigation.jsx';
import NotificationItem from '../componenets/NotificationItem/NotificationItem'
import './Notification.css';

const NotificationsArray = [
    {
        title: 'Exercise 1',
        subtitle: 'Do first exercise 10 times...'
    },
    {
        title: 'Exercise 2',
        subtitle: 'Do second exercise 20 times...'
    },
    {
        title: 'Exercise 3',
        subtitle: 'Do third exercise 30 times...'
    },
    {
        title: 'Exercise 4',
        subtitle: 'Do fourth exercise 40 times...'
    }
]

function Notification(props) {
    return(
        <>
            <Card rounded width={340} height={610} className='card'>
                <CardContent>
                    <H4 className='notification-card-title'>Notification</H4>
                    {NotificationsArray.map((el) => {
                        return <NotificationItem title={el.title} subtitle={el.subtitle}/>
                    })}
                </CardContent>
                <Navigation />
            </Card>
        </>
    )
} 

export default Notification;